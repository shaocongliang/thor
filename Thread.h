#ifndef THOR_THREAD_H
#define THOR_THREAD_H
#include <unistd.h>
#include <pthread.h>

#include <string>
#include <functional>
#include <NonCopyable.h>
namespace thor{
    pid_t getThreadId();
    class Thread : public NonCopyable{
        public:
            typedef std::function<void(void)> ThreadFunc;
            explicit Thread(const std::function<void(void)> &func);
            explicit Thread(const std::function<void(void)> &func, const std::string &name);
            void start();
            bool isRunning() const { return running_; }
        private:
            bool running_;
            std::string name_;
            pthread_t pthreadId_;
            pid_t tid_;
            std::function<void(void)> func_;
    };
}
#endif // 