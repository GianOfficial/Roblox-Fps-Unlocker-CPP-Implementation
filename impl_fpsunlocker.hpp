// Credits to gogo1000
// Q: How does this work?
// A: It reads the instance of the task scheduler class and the pad basically adds 272 bytes to the start because the Frame Delay offset is 272

// tl;dr Reverse the address/offset by yourself

// Updated as of 6/11/2020

namespace FPSUnlocker
{
      class TaskScheduler
      {
      public:
           char Pad[272];
           double FPS;
      };

      int Unlock_Fps(lua_State* L)
      {
           TaskScheduler* TaskScheduling = *reinterpret_cast<TaskScheduler**>(ASLR(0x259DB20));
           const double FPS = 1.0 / 500.0; //500.0 is your fps decision
           TaskScheduling->FPS = FPS;
           return 0;
      }
}
