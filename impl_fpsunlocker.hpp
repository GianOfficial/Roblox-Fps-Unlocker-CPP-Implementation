// Credits to gogo1000
// Q: How does this work?
// A: It reads the instance of the task scheduler class and the pad basically adds 272 bytes to the start because the Frame Delay offset is 272

// tl;dr Reverse the address/offset by yourself

// Updated as of 15/11/2020 (Last Update, I will not provide the address/offset next week) 

namespace FPSUnlocker
{
      typedef struct
      {
          char Pad[272];
          double FPS;
      } TaskScheduler;

      int Unlock_Fps()
      {
           TaskScheduler* TaskScheduling = *reinterpret_cast<TaskScheduler**>(ASLR(0x259FC30));
           const double FPS = 1.0 / 500.0; //500.0 is your fps decision
           TaskScheduling->FPS = FPS;
           return 0;
      }
}
