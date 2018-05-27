#include <EventLoop.h>
using namespace thor;

EventLoop g_loop;
int main(int agrc, char **argv) {
  g_loop.loop();
  return 0;
}