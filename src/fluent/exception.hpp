/*-
 * Copyright (c) 2015 Masayoshi Mizutani <mizutani@sfc.wide.ad.jp>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SRC_FLUENT_EXCEPTION_HPP__
#define __SRC_FLUENT_EXCEPTION_HPP__

#include <exception>
#include <sstream>

namespace fluent {
  namespace Exception {
    class TypeError : public std::exception {
    private:
      std::string errmsg_;
    public:
      TypeError(const std::string &errmsg) : errmsg_(errmsg) {}
      virtual ~TypeError() throw () {}
      virtual const char* what() const throw() {
        return this->errmsg_.c_str();
      }
    };

    class IndexError : public std::exception {
    private:
      size_t idx_, max_;
    public:
      IndexError(size_t idx, size_t max) : idx_(idx), max_(max) {}
      virtual ~IndexError() throw() {}
      virtual const char* what() const throw() {
        std::stringstream ss;
        ss << "out of range: " << this->idx_ << ", should < " <<
          this->max_;
        return ss.str().c_str();
      }
    };

    class KeyError : public std::exception {
    private:
      std::string key_;
    public:
      KeyError(const std::string &key) : key_(key) {}
      virtual ~KeyError() throw() {}
      virtual const char* what() const throw() {
        std::stringstream ss;
        ss << "key \"" << this->key_ << "\" is not found";
        return ss.str().c_str();
      }
    };
    
  }
}
  

#endif   // __SRC_FLUENT_EXCEPTION_H__
