# SecurePad: A Simple Encrypted Console Notepad
 SecurePad is a lightweight, console-based text editor written in C++ with a focus on privacy. It allows you to create and edit text files, which are automatically encrypted    upon saving and decrypted when opened, ensuring your notes are not stored in plain text.

 <img width="1726" height="926" alt="image" src="https://github.com/user-attachments/assets/0dc72743-f4ec-4243-b28a-03969772c849" />
 <img width="1736" height="923" alt="image" src="https://github.com/user-attachments/assets/10e69cb0-5c54-4096-9a15-c9366f5c1949" />
 <img width="1731" height="922" alt="image" src="https://github.com/user-attachments/assets/20be3c4d-9ec0-48b7-aba7-5fe37433147c" />


## Features: 
1. Create & Edit: Simple interface for creating new files or editing existing ones.
2. Automatic Encryption: Files are automatically encrypted on save, so you don't have to think about it.
3. Seamless Decryption: Files are decrypted in memory when you open them for editing.
4. Smart File Naming: Files are automatically named first_word.txt based on the first word of their content.
5. Safe Exit: Exit the editor without saving your changes at any time.
6. Minimalist: Runs entirely within the console, making it fast and portable.
## How It Works:
  File Organization: All saved files are stored in a files/ directory, which is created automatically in the same folder as the executable.
  The Encryption/Decryption ProcessWhen you press Ctrl + S to save a file, the application runs a simple encryption algorithm on the entire text before writing it to disk.
  When you open an existing file, the program reads the encrypted content and applies the decryption algorithm to restore it to plain text for editing. This provides a basic     layer of privacy, preventing casual snooping by ensuring the files on your disk are not human-readable.
## Controls:
  The controls are designed to be simple and intuitive.
  KeyAction: Ctrl + SEncrypts and saves the current file. The filename will be the first word you wrote, ending with .txt.
  Escape: Exits the editor and returns to the main menu without saving any changes.
## Getting Started:
  Prerequisites: A C++ compiler (like G++, Clang, or MSVC).
