## day1

- 实现了一个简易的窗口，以及基本的播放/暂停音乐的功能
  - 仍需要手动输入名字，且没有联想功能

![1-1](.\pic\1-1.png)



### what did I do

- 使用QT designer画出简易窗口界面，并在QT creator中进行部署得到对应头文件

- 派生出我们需要的`MusicDialog`基类并实现部分细节

  - `Play`,`Pause`,`Close`三个按键的功能

  - 播放音乐通过调用c库函数`mciSendString()`来实现

    ```c++
    bool mciSendString(const wchar_t *Cmd, NULL, 0, NULL);
    /***
    后三个参数不重要
    命令参数包括：open/play/pause/resume/stop/close filename
    
    可以通过QString.toStdWString().c_str()得到const wchar_t*字符串
    */
    ```

    

