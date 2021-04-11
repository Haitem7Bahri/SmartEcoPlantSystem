## Threading Testing:

A simple program to test the **threading** capabilities of raspberry pi before implementing it on the actual system.
The program will run two different tasks each in its own thread.

Task 1: **blinkingConst** will simply flash a led connected to **GPIO17** port with constant frequency.
Task 2: **blinkingVar** will simply flash a led connected to **GPIO18*** port with varying frequency.

Each task is placed in its own class file:
  **blinkingConst** in **blinkingConst.cpp** file.
  **blinkingVar** in **blinkingVar.cpp** file.
