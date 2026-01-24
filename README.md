# ConsolePad: A Simple Encrypted Console Notepad
 ConsolePad is a lightweight, console-based text editor written in C++ with a focus on privacy. It allows you to create and edit text files, which are automatically encrypted    upon saving and decrypted when opened, ensuring your notes are not stored in plain text.

<img width="1710" height="907" alt="Screenshot 2025-10-19 083020" src="https://github.com/user-attachments/assets/6e74adbc-e0bf-4225-bdd7-b61dad0472ae" />
<img width="1719" height="906" alt="Screenshot 2025-10-19 083107" src="https://github.com/user-attachments/assets/3269540d-e449-434b-9bd8-d563ca9a43e5" />
<img width="1713" height="913" alt="Screenshot 2025-10-19 083146" src="https://github.com/user-attachments/assets/269c1aee-ede7-40b3-af7b-a07cab68ea18" />



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
  KeyAction: Ctrl + S encrypts and saves the current file. The filename will be the first word you wrote.
  Escape: Exits the editor and returns to the main menu without saving any changes.
## Getting Started:
  Prerequisites: A C++ compiler (like G++, Clang, or MSVC).
