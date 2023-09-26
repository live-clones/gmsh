#ifndef CFMB_TIMER_H
#define CFMB_TIMER_H

#include <map>
#include <chrono>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

namespace IFF{
  
  class Timer{
  
  public:
    Timer(){
      m_initTag="Total time";
      m_currentStructTag = "";
      tic(m_initTag);
      m_sep = "   ";
      std::string test= "test";
      _countTags(test);
    }
    ~Timer(){}

    void tic(const std::string &str){
      if(m_sep.length() > 0){
	size_t pos = str.find(m_sep);
	if(pos != std::string::npos){
	  std::cout << "Timer::tic(str): Forbiden tag name. Should not contain 3 spaces in a row" << std::endl;
	  std::cout << "Problematic tag: " << str << std::endl;
	  exit(0);
	}
      }
      m_currentStructTag = m_currentStructTag + m_sep + str;
      m_tics[m_currentStructTag] = std::chrono::high_resolution_clock::now();
    }
  
    void toc(){
      std::chrono::duration<double> elapsed_time = std::chrono::high_resolution_clock::now() - m_tics[m_currentStructTag];
      m_times_strucTags[m_currentStructTag] += elapsed_time.count();
      std::string tag = _extractLastTag(m_currentStructTag);
      m_times_tags[tag] += elapsed_time.count();
    }

    std::string _extractLastTag(std::string &structTag){
      std::string reversedSep = m_sep;
      std::reverse(reversedSep.begin(), reversedSep.end());
      std::string reversedST = structTag;
      std::reverse(reversedST.begin(), reversedST.end());
      size_t pos = reversedST.find(reversedSep);
      std::string lastTag = reversedST.substr(0, pos);
      std::reverse(lastTag.begin(), lastTag.end());
      reversedST.erase(0, pos + reversedSep.length());
      std::reverse(reversedST.begin(), reversedST.end());
      structTag = reversedST;
      return lastTag;
    }

    std::string _getLastTag(const std::string &structTag){
      std::string reversedSep = m_sep;
      std::reverse(reversedSep.begin(), reversedSep.end());
      std::string reversedST = structTag;
      std::reverse(reversedST.begin(), reversedST.end());
      size_t pos = reversedST.find(reversedSep);
      std::string lastTag = reversedST.substr(0, pos);
      std::reverse(lastTag.begin(), lastTag.end());
      return lastTag;
    }

    size_t _countTags(const std::string &structTag){
      std::string s = structTag;
      size_t pos = s.find(m_sep);
      size_t nTags = 0;
      if(structTag.length() > 0)
	nTags = 1;
      while(pos != std::string::npos){
	nTags++;
	s = s.substr(pos + m_sep.length());
	pos = s.find(m_sep);
      }
      return nTags;
    }
  
    void end(){
      toc();
    }

    void printDBG(){
      std::cout << "v1" << std::endl;
      for(auto &kv: m_times_strucTags)
	std::cout << kv.first << " " << kv.second << " / nTags: " << _countTags(kv.first) << std::endl;
      std::cout << std::endl;
      std::cout << "v2" << std::endl;
      for(auto &kv: m_times_tags)
	std::cout << kv.first << " " << kv.second <<  std::endl;
      std::cout << std::endl;
    }
  
    void printSumUp(const std::string &title = "Timer infos"){
      double totalTime = m_times_tags[m_initTag];
      std::string atomicOffset = "      |";
      std::string offset = "--  ";
      std::cout << "---------------------------------------------------------------- " << title << std::endl;
    
      //Print struct sum up
      std::cout << "+++++++++++ Structured Sum up" << std::endl;
      size_t nPreviousTags = 0;
      for(auto &kv: m_times_strucTags){
	size_t nCurrentTags = _countTags(kv.first);
	std::string currentOffset = offset;
	for(size_t k=1; k<nCurrentTags; k++)
	  currentOffset += atomicOffset;
	if(nCurrentTags<nPreviousTags)
	  std::cout << currentOffset << std::endl;
	if(nCurrentTags>nPreviousTags)
	  std::cout << currentOffset << std::endl;
	if(nCurrentTags > 1)
	  currentOffset += " -> ";
	double percTotalTime = round(kv.second/totalTime * 100 * 100)/100;
	std::string parentTag = kv.first;
	std::string lastTag = _extractLastTag(parentTag);
	double percParentTime = round(kv.second/m_times_strucTags[parentTag] * 100 * 100)/100;
	std::cout << currentOffset << lastTag << ": " << kv.second << " (" << percTotalTime << "% Tot/ " << percParentTime << "% Func)" << std::endl;
	nPreviousTags = nCurrentTags;
      }
    
      //Print unstruct sum up
      std::vector<std::pair<std::string, double>> vectTagsPerc;
      vectTagsPerc.reserve(m_times_tags.size());
      for(auto const & kv: m_times_tags){
	if(kv.first != m_initTag){
	  double perc = round(kv.second/totalTime * 100 * 100)/100;
	  vectTagsPerc.push_back(std::make_pair(kv.first, perc));
	}
      }
      std::sort(vectTagsPerc.begin(), vectTagsPerc.end(), [&](std::pair<std::string, double> i1, std::pair<std::string, double> i2){return i1.second > i2.second;});

      std::cout << "--   " << std::endl;
      std::cout << "+++++++++++ Unstructured Sum up" << std::endl;
      std::cout << "--   " << std::endl;
      std::cout << "-- " << m_initTag << ": " << totalTime << std::endl;
      std::cout << "--   |" << std::endl;
      // for(auto const & kv: m_times_tags)
      for(auto const & kv: vectTagsPerc)
	std::cout << "--   | -> " << kv.first << ": " << m_times_tags[kv.first] << " (" << kv.second << "%)" << std::endl;
      std::cout << "--" << std::endl;
      std::cout << "--------------------------------------------------------------------------------" << std::endl;
    }
    std::map<std::string, double> m_times_tags;
    std::map<std::string, double> m_times_strucTags;
    std::string m_currentStructTag;
    std::string m_sep;
    std::string m_initTag;
    std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> m_tics;
  };

  class GlobalTimer{
  private:
    static Timer timer;
    static bool silent;
  public:
    static void enable(){silent = false;}
    static void tic(const std::string &str){
      if(!silent)
	timer.tic(str);
    }
    static void toc(){
      if(!silent)
	timer.toc();
    }

    static void end(){
      if(!silent)
	timer.end();
    }
    static void printDBG(){
      if(!silent)
	timer.printDBG();
    }
    static void printSumUp(const std::string &title = "Timer infos"){
      if(!silent)
	timer.printSumUp(title);
    }
  };

}
#endif
