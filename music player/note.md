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
    bool mciSendString(const wchar_t *Cmd, char* errMessage,\
                       size_t MessageLen, NULL);
    /***
    后三个参数不重要（用于返回错误信息) 
    命令参数包括：open/play/pause/resume/stop/close filename
    成功执行返回0
    */
    ```




### some matters

- 网易云下载的`.mp3`有无法被`mciSendString`打开的可能，是因为tag超出正常大小的原因，下载`mp3tag`工具来去除tag解决

- `QString`和`const wchar_t*`的转换：

  ```c++
  const wchar_t* wStr = reinterpret_cast<const wchar_t*>(qStr.utf16());
  
  //引入std::wstring
  wStr = qStr.toStdWString().c_str();
  ```

  

## day2

- 实现了读取当前路径下的所有`.mp3`文件，并用`QListWidget`实现简单的可视化



![2-1](.\pic\2-1.png)

### what did I do

- 使用`#include <dirent.h>`头文件中的函数进行读取，得到的`struct dirent`结构体中包含`char d_name[LEN]`,`int d_type`等信息

  ```c++
  const char* path = "";
  DIR *dir = opendir(path);
  struct dirent* pdir = nullptr;
  while(nullptr != (pdir = readdir(dir))){
      //dosomething
  }
  ```

- 使用`QListWidget`的`addItem()`方法将读取到的音乐加入列表（后续考虑用功能更全面的`QListView`进行优化），绑定`itemDoubleClicked()`时的操作







 ### some matters

- 使用`Impl *pImpl`模式减少了部分构建时间

- 使用`mciSendString`函数的时候，因为第一个参数必须使用`const wchar_t*`，一开始使用的方案是一个预分配空间的`wchar_t *`指针，但是经常出现bug导致无法pause/stop/close，遂更改为上文中提到的`reinterpret_cast`形式。bug原因是`QString.toWCharArray()`方法不会补充结尾的`\0`,故可能会有错误的结尾

  ```c++
  #define MAX_NAME_LEN 100
  wchar_t wCmd[MAX_NAME_LEN];
  
  qCmd.toWCharArray(wCmd);
  
  msiSendString(qCmd, NULL, 0, NULL);
  ```

  还有一个问题就是该函数可以同时打开多个音乐，因此要注意关闭上次的音乐
  



## day3

- 添加了一个刷新按钮，可以更新列表
- 添加了文件格式可选项
- 添加了前缀补全功能

![image-20211124234934467](.\pic\3-1.png)

### what did I do

- 用`std::lower_bound`和`QVector::insert`实现有序插入，没有实现删除因为需要遍历列表，改为点击音乐不存在时删除
- 将`playMusic()`,`setMusicList()`等部分模块化方便调用
- 使用`QCompleter`库实现前缀补全

### some matters

- 播放列表中的问题：
  - 中文显示乱码问题：是因为`char *`转`QString`的问题，使用`QString::fromLocal8Bit(char *)`进行构造即可
  - 文件名含空格：使用`"\"filename\""`即可
  - 删除时调用`removeItemWidget(QListWidgetItem *)`后，需要`delete`才能真正删除

