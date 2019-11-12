package org.geuz.onelab;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Bitmap.CompressFormat;
import android.opengl.GLUtils;
import android.os.Environment;

public class StringTexture {
  private String _text;
  private Bitmap _bitmap;
  private int[] _textures = new int[1]; // Texture pointer

  public StringTexture(String s)
  {
    _text = s;
    getBitmapFromText(12.0f, Color.BLACK);
  }

  private void getBitmapFromText(float textSize, int textColor)
  {
    Paint paint = new Paint();
    paint.setTextSize(textSize);
    paint.setColor(textColor);
    paint.setTextAlign(Paint.Align.LEFT);
    int width = (int)(paint.measureText(_text) + 2.5f); // round
    int baseline = (int)(textSize + 2.5f);
    int height = (int)(baseline + paint.descent() + 2.5f);
    _bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
    _bitmap.eraseColor(Color.TRANSPARENT);
    Canvas canvas = new Canvas(_bitmap);
    canvas.setBitmap(_bitmap);
    canvas.drawText(_text, 0, baseline, paint);
  }

  private void loadGLTexture(GL10 gl)
  {
    if(_bitmap == null) return;
    gl.glGenTextures(1, _textures, 0);

    gl.glBindTexture(GL10.GL_TEXTURE_2D, _textures[0]);

    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER,
                       GL10.GL_NEAREST);
    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER,
                       GL10.GL_LINEAR);

    GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, _bitmap, 0);

    _bitmap.recycle();
  }

  public void draw(GL10 gl, int x, int y)
  {
    gl.glEnable(GL10.GL_TEXTURE_2D);
    // VERTEX
    float vertex[] = {
      -1.0f, -1.0f, 0.0f, // bottom left
      -1.0f, 1.0f,  0.0f, // top left
      1.0f,  -1.0f, 0.0f, // bottom right
      1.0f,  1.0f,  0.0f // top right
    };
    FloatBuffer vertexBuffer;
    ByteBuffer vertexByteBuffer = ByteBuffer.allocateDirect(vertex.length * 4);
    vertexByteBuffer.order(ByteOrder.nativeOrder());
    vertexBuffer = vertexByteBuffer.asFloatBuffer();
    vertexBuffer.put(vertex);
    vertexBuffer.position(0);

    // TEXTURE
    FloatBuffer textureBuffer; // buffer holding the texture coordinates
    float texture[] = {
      0.0f, 1.0f, // top left
      0.0f, 0.0f, // bottom left
      1.0f, 1.0f, // top right
      1.0f, 0.0f // bottom right
    };
    ByteBuffer textureByteBuffer =
      ByteBuffer.allocateDirect(texture.length * 4);
    textureByteBuffer.order(ByteOrder.nativeOrder());
    textureBuffer = textureByteBuffer.asFloatBuffer();
    textureBuffer.put(texture);
    textureBuffer.position(0);
    loadGLTexture(gl);
    gl.glBindTexture(GL10.GL_TEXTURE_2D, _textures[0]);

    // DRAW
    gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
    gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
    gl.glColor4f(1, 1, 1, 1);
    gl.glEnable(GL10.GL_BLEND);
    gl.glBlendFunc(GL10.GL_SRC_COLOR, GL10.GL_ONE_MINUS_SRC_ALPHA);
    gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);
    gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
    gl.glDrawArrays(GL10.GL_TRIANGLE_STRIP, 0, vertex.length / 3);
    gl.glDisable(GL10.GL_BLEND);
    gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
    gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
    gl.glDisable(GL10.GL_TEXTURE_2D);
  }

  public static byte[] getBytesFromString(String s, int textSize)
  {
    // Generate the bitmap
    int textColor = Color.BLACK;
    Paint paint = new Paint();
    paint.setTextSize(textSize);
    paint.setColor(textColor);
    paint.setTextAlign(Paint.Align.LEFT);
    int width = (int)(paint.measureText(s) + 0.5f); // round
    int i;
    for(i = 2; i <= width; i *= 2)
      ;
    width = i;
    int baseline = (int)(textSize + 0.5f);
    int height = (int)(baseline + paint.descent() + 0.5f);
    for(i = 2; i <= height; i *= 2)
      ;
    height = i;
    Bitmap bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
    bitmap.eraseColor(Color.WHITE);
    Canvas canvas = new Canvas(bitmap);
    canvas.setBitmap(bitmap);
    canvas.drawText(s, 0, baseline, paint);
    // Get the pixel in a map
    ByteBuffer buffer = ByteBuffer.allocateDirect(width * height);
    buffer.order(ByteOrder.nativeOrder());
    buffer.position(0);
    for(int y = 0; y < height; y++)
      for(int x = 0; x < width; x++)
        buffer.put(
          (byte)((bitmap.getPixel(x, y) == Color.BLACK) ? 0xFF : 0x00));
    buffer.position(0);
    byte[] b = new byte[buffer.capacity()];
    buffer.get(b);
    return b;
  }
  public static int getWidthFromString(String s, int textSize)
  {
    Paint paint = new Paint();
    paint.setTextSize(textSize);
    paint.setTextAlign(Paint.Align.LEFT);
    int ret = (int)(paint.measureText(s) + 0.5f);
    int i;
    for(i = 2; i <= ret; i *= 2)
      ;
    ret = i;
    return ret;
  }
  public static int getRealWidthFromString(String s, int textSize)
  {
    Paint paint = new Paint();
    paint.setTextSize(textSize);
    paint.setTextAlign(Paint.Align.LEFT);
    return (int)(paint.measureText(s) + 0.5f);
  }
  public static int getHeightFromString(String s, int textSize)
  {
    Paint paint = new Paint();
    paint.setTextSize(textSize);
    paint.setTextAlign(Paint.Align.LEFT);
    int ret = (int)(textSize + 0.5f + paint.descent() + 0.5f);
    int i;
    for(i = 2; i <= ret; i *= 2)
      ;
    ret = i;
    return ret;
  }
}
