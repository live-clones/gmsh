// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstring>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "gl2mp4.h"

#if defined(HAVE_FFMPEG)

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
}

struct mp4Writer::data {
  AVFormatContext *format = nullptr;
  AVCodecContext *codec = nullptr;
  AVStream *stream = nullptr;
  AVFrame *frame = nullptr;
  AVPacket *packet = nullptr;
  SwsContext *sws = nullptr;
  // the size of the pictures, and of the movie (even, as the chroma of
  // YUV 4:2:0 is sampled every other pixel)
  int width = 0, height = 0;
  long long count = 0;
  bool failed = false, opened = false;
};

mp4Writer::mp4Writer() : _d(new data) {}

mp4Writer::~mp4Writer()
{
  close();
  delete _d;
}

static std::string avError(int err)
{
  char buf[AV_ERROR_MAX_STRING_SIZE] = {0};
  av_strerror(err, buf, sizeof(buf));
  return buf;
}

// send a frame (or nullptr at the end) and write the packets that come out
static bool encode(mp4Writer::data *d, AVFrame *frame);

bool mp4Writer::open(const std::string &name, int width, int height,
                     double fps)
{
  data *d = _d;
  int w = width & ~1, h = height & ~1;
  if(w < 2 || h < 2) {
    Msg::Error("Picture of %dx%d pixels too small for a movie", width, height);
    return false;
  }
  d->width = width;
  d->height = height;
  if(avformat_alloc_output_context2(&d->format, nullptr, "mp4",
                                    name.c_str()) < 0 ||
     !d->format) {
    Msg::Error("Could not create the MP4 file '%s'", name.c_str());
    return false;
  }
  const AVCodec *codec = avcodec_find_encoder(AV_CODEC_ID_H264);
  if(!codec) codec = avcodec_find_encoder(AV_CODEC_ID_MPEG4);
  if(!codec) {
    Msg::Error("FFmpeg has neither an H.264 nor an MPEG-4 encoder");
    return false;
  }
  d->stream = avformat_new_stream(d->format, nullptr);
  d->codec = avcodec_alloc_context3(codec);
  if(!d->stream || !d->codec) return false;
  AVRational rate = av_d2q(fps, 1000);
  d->codec->width = w;
  d->codec->height = h;
  d->codec->pix_fmt = AV_PIX_FMT_YUV420P;
  d->codec->time_base = av_inv_q(rate);
  d->codec->framerate = rate;
  d->codec->gop_size = 12;
  if(d->format->oformat->flags & AVFMT_GLOBALHEADER)
    d->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
  // a picture of a model is mostly flat colours and sharp edges, which a
  // low compression keeps
  if(!strcmp(codec->name, "libx264")) {
    av_opt_set(d->codec->priv_data, "crf", "18", 0);
    av_opt_set(d->codec->priv_data, "preset", "slow", 0);
  }
  else if(codec->id == AV_CODEC_ID_MPEG4) {
    d->codec->flags |= AV_CODEC_FLAG_QSCALE;
    d->codec->global_quality = FF_QP2LAMBDA * 2;
  }
  else // e.g. the hardware encoders, which want a bit rate
    d->codec->bit_rate = (int64_t)(0.2 * w * h * fps);
  int err = avcodec_open2(d->codec, codec, nullptr);
  if(err < 0) {
    Msg::Error("Could not open the %s encoder: %s", codec->name,
               avError(err).c_str());
    return false;
  }
  avcodec_parameters_from_context(d->stream->codecpar, d->codec);
  d->stream->time_base = d->codec->time_base;
  if((err = avio_open(&d->format->pb, name.c_str(), AVIO_FLAG_WRITE)) < 0) {
    Msg::Error("Could not open '%s': %s", name.c_str(), avError(err).c_str());
    return false;
  }
  if((err = avformat_write_header(d->format, nullptr)) < 0) {
    Msg::Error("Could not write the header of '%s': %s", name.c_str(),
               avError(err).c_str());
    return false;
  }
  d->opened = true;
  d->frame = av_frame_alloc();
  d->packet = av_packet_alloc();
  d->frame->format = AV_PIX_FMT_YUV420P;
  d->frame->width = w;
  d->frame->height = h;
  av_frame_get_buffer(d->frame, 0);
  d->sws = sws_getContext(w, h, AV_PIX_FMT_RGB24, w, h, AV_PIX_FMT_YUV420P,
                          SWS_BICUBIC, nullptr, nullptr, nullptr);
  Msg::Info("Writing a %dx%d movie at %g frames per second with the %s "
            "encoder", w, h, av_q2d(rate), codec->name);
  return d->frame && d->packet && d->sws;
}

static bool encode(mp4Writer::data *d, AVFrame *frame)
{
  int err = avcodec_send_frame(d->codec, frame);
  if(err < 0) {
    Msg::Error("Could not encode a frame: %s", avError(err).c_str());
    return false;
  }
  while(true) {
    err = avcodec_receive_packet(d->codec, d->packet);
    if(err == AVERROR(EAGAIN) || err == AVERROR_EOF) return true;
    if(err < 0) {
      Msg::Error("Could not encode a frame: %s", avError(err).c_str());
      return false;
    }
    av_packet_rescale_ts(d->packet, d->codec->time_base, d->stream->time_base);
    d->packet->stream_index = d->stream->index;
    err = av_interleaved_write_frame(d->format, d->packet);
    av_packet_unref(d->packet);
    if(err < 0) {
      Msg::Error("Could not write a frame: %s", avError(err).c_str());
      return false;
    }
  }
}

bool mp4Writer::write(PixelBuffer *buffer)
{
  data *d = _d;
  if(!d->opened || d->failed) return false;
  if(buffer->getWidth() != d->width || buffer->getHeight() != d->height ||
     buffer->getNumComp() != 3 || buffer->getType() != GL_UNSIGNED_BYTE) {
    Msg::Error("The pictures of a movie must be RGB bytes of the same size");
    d->failed = true;
    return false;
  }
  if(av_frame_make_writable(d->frame) < 0) {
    d->failed = true;
    return false;
  }
  // OpenGL's first row is the bottom one: read the rows backwards
  const unsigned char *pixels = (const unsigned char *)buffer->getPixels();
  int stride = 3 * d->width;
  const uint8_t *src[1] = {pixels + (d->height - 1) * stride};
  int srcStride[1] = {-stride};
  sws_scale(d->sws, src, srcStride, 0, d->frame->height, d->frame->data,
            d->frame->linesize);
  d->frame->pts = d->count++;
  if(!encode(d, d->frame)) d->failed = true;
  return !d->failed;
}

bool mp4Writer::close()
{
  data *d = _d;
  bool ok = !d->failed;
  if(d->opened) {
    ok = encode(d, nullptr) && ok;
    ok = (av_write_trailer(d->format) >= 0) && ok;
    d->opened = false;
  }
  if(d->format && d->format->pb) avio_closep(&d->format->pb);
  if(d->format) avformat_free_context(d->format);
  if(d->codec) avcodec_free_context(&d->codec);
  if(d->frame) av_frame_free(&d->frame);
  if(d->packet) av_packet_free(&d->packet);
  if(d->sws) sws_freeContext(d->sws);
  *d = data();
  return ok;
}

#else

struct mp4Writer::data {};
mp4Writer::mp4Writer() : _d(nullptr) {}
mp4Writer::~mp4Writer() { delete _d; }
bool mp4Writer::open(const std::string &name, int width, int height,
                     double fps)
{
  Msg::Error("Gmsh must be compiled with FFmpeg to write MP4 movies");
  return false;
}
bool mp4Writer::write(PixelBuffer *buffer) { return false; }
bool mp4Writer::close() { return true; }

#endif
