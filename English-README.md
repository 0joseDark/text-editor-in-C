# text editor in C

- 64-bit text editor in C
- A basic program in C to create a 64-bit text editor with a graphical interface on Windows 10. We will use the Windows API (WinAPI) to develop the graphical interface. The code includes basic features such as open, create, modify, save, save as, and a text box to display the file path.

1. **Create the Main Window**:
   - Register a window class (`WNDCLASS`) and create the main window.
   - Set up the menu with options like "New," "Open," "Save," "Save As," and "Exit."

2. **Add a Text Box**:
   - Create a text box with the `ES_MULTILINE` style to support multiple lines.

3. **Add Functionality**:
   - Use standard Windows dialogs to open and save files.
   - Implement functions to handle files (`OpenFile`, `SaveFile`, `SaveFileAs`).

4. **Handle Messages**:
   - In `WindowProc`, process messages like `WM_COMMAND` to handle menu clicks.

---

### **How to Compile**

1. Save the code in a file named `editor_texto.c`.
2. Open the Visual Studio Developer Command Prompt.
3. Execute:
   ```bash
   cl editor_texto.c /link user32.lib gdi32.lib comdlg32.lib
   ```
4. The executable `editor_texto.exe` will be generated and can be run directly on Windows 10.

---

### **How to Use Dev-C++ to Compile the Text Editor in C**

Dev-C++ is a lightweight and free IDE that facilitates the compilation of C/C++ programs. Here’s a step-by-step guide to compile and run the text editor program in Dev-C++:

---

#### 1. **Install Dev-C++**
- If you don’t already have Dev-C++, download it from [Bloodshed Dev-C++](https://sourceforge.net/projects/orwelldevcpp/).
- Install the program by following the installer steps.

---

#### 2. **Open Dev-C++**
- Launch the program.
- In the menu bar, click **File > New > Project**.
- Select the project type as **Console Application**, choose **C** as the language, and click **OK**.
- Choose the project’s location and name (e.g., `EditorTextoDev`).

---

#### 3. **Insert the Code**
- In the main window, delete the default code.
- Copy the text editor code provided and paste it into Dev-C++'s code editor.

---

#### 4. **Configure Project Options**
- Go to **Tools > Compiler Options** and ensure the compiler is set to support **64 bits**.
- To ensure the program compiles correctly with the Windows API, add the necessary libraries:
  1. Go to **Tools > Compiler Options > Add the following commands...**.
  2. Add the following flags in the additional parameters field:
     ```
     -mwindows -luser32 -lgdi32 -lcomdlg32
     ```

---

#### 5. **Save the Project**
- Click **File > Save Project As...** and choose where to save the project.

---

#### 6. **Compile the Program**
- Click **Execute > Compile & Run** or press **F11**.
- Dev-C++ will compile the program, and if there are no errors, it will run the text editor directly.

---

#### 7. **Test the Program**
- When the program opens, you will see the graphical interface of the text editor with menu options.
- You can create, open, and save text files, testing the implemented features.

---

### **Important Note**
- Ensure Dev-C++ is configured to use the correct **MinGW** compiler that supports the Windows API.
- If the editor shows errors related to Windows libraries, verify that the library names (like `user32`, `gdi32`, and `comdlg32`) were correctly included in the compiler options.
