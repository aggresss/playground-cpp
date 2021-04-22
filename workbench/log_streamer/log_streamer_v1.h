#ifndef LOG_STREAMER_V1_H_
#define LOG_STREAMER_V1_H_

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define LOG_V1 \
    v1::LogCall(__FILE__, "LOG_V1") & v1::LogStreamer()

namespace v1 {

class LogStreamer {
   public:
    LogStreamer(const char* arg = "", const LogStreamer* prior = nullptr)
        : arg_(arg), prior_(prior) {}

    LogStreamer operator<<(const char* arg) const {
        return LogStreamer(arg, this);
    }

    template <typename... U>
    void Call(U... args) const {
        std::cout << this->arg_ << std::endl;
        if (this->prior_ != nullptr) {
            this->prior_->Call(this->arg_, args...);
        } else {
            (std::cout << ... << args) << std::endl;
        }
    }

   private:
    const char* arg_;
    const LogStreamer* prior_;
};

class LogCall final {
   public:
    LogCall(const char* file, const char* message)
        : file_(file), message_(message) {}

    void operator&(const LogStreamer& streamer) {
        streamer.Call(file_, message_);
    }

   private:
    const char* file_;
    const char* message_;
};

}  // namespace v1

#endif  // LOG_STREAMER_V1_H_
