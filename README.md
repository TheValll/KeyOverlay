# KeyOverlay App 🖥️

This application creates a graphical user interface (GUI) using the Qt framework to monitor the status of various keys and buttons on a Windows system. It provides real-time visual feedback on whether a key or button is pressed or released.

## Features 🛠️

- Real-time monitoring of key/button status
- Visual indication of key/button status changes
- Customizable key/button monitoring

![image](https://github.com/TheValll/KeyOverlay/assets/81711481/875079c8-cfaa-4168-9b8c-b6159735ccee)

## How to Use 🚀

1. **Launching the Application:**
   - Open the application using Qt Creator or by running the executable file.
   
2. **Monitoring Keys/Buttons:**
   - The application visually represents the status of keys/buttons listed in the UI.
   - To modify the keys/buttons to monitor:
     - Open `mainwindow.ui` in Qt Creator.
     - Edit the QPushButton objects and rename them according to the desired keys/buttons.
     - Update the corresponding function calls in the code (`mainwindow.cpp`) with the appropriate key codes.
     - Refer to Microsoft's [Virtual-Key Codes documentation](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes) for key code references.

3. **Building the Application:**
   - To build the application using Qt Creator:
     - Open the project in Qt Creator.
     - Configure the project settings if necessary.
     - Build the project using the build/run option in Qt Creator.

4. **Interpreting Visual Feedback:**
   - When a key/button is pressed, its corresponding button in the UI changes color to indicate the pressed state.
   - When a key/button is released, its corresponding button in the UI reverts to its default color.

## Dependencies 📦

- Qt framework
- Windows API

## Credits 🙌

- Developed by [TheValll]
