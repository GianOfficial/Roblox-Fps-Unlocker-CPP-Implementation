// Credits to gogo1000
// Q: How does this work?
// A: It reads the instance of the task scheduler class and the pad basically adds 272 (0x110) bytes to the start because the Frame Delay offset is 272 (0x110)

//tl;dr Reverse the address/offset by yourself

namespace FPSUnlocker
{
      class TaskScheduler
      {
      public:
           char Pad[0x110]; //272
           double FPS;
      };

      int Unlock_Fps(lua_State* L)
      {
           TaskScheduler* TaskScheduling = *reinterpret_cast<TaskScheduler**>(ASLR(0x257DE70));
           const double FPS = 1.0 / 500.0; //500.0 is your fps decision
           TaskScheduling->FPS = FPS;
           return 0;
      }
}
