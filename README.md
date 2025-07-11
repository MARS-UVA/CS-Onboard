# MARS and ROS2

Hello there 👋, this is a repository (that may or may not be similar to Cavalier Autonomous Racing onboarding) that will hopefully introduce you to the basic frameworks we use, such as Git, Linux, and ROS2. 

Learning this might be difficult depending on how well-versed you are already, so be patient and take your time. If you have any questions -- first, you should join the MARS discord, but you can also dm me at z_eric (also on discord). 

## What Code? How Code?

Our codebase is a mix of Python and C++ (with ROS2 which I'll explain later), which need to be downloaded separately. 

I use Visual Studio **Code**. This is a lightweight code editor, however it doesn't really come with anything. I think I used this link to setup C++: https://code.visualstudio.com/docs/cpp/config-mingw, and setting up Python is probably a lot easier. This is a very common editor, but many people (C/C++ developers mainly) also use Visual Studio since it comes with a lot of C++ tools (I think).

C++ is a compiler-based language; you need a compiler in order to run files. ROS2 handles it for us using the tool **colcon**, but it uses gcc or some other compiler in the background. You have to compile code into an executable in order to run anything.

Python is interpreter-based. You download the interpreter, select it, and run code. To actually learn syntax for these two languages, I recommend w3schools, codingbat, or looking at or doing something hands-on.

## What is Git?

If you don't have it, set it up. https://docs.github.com/en/get-started/git-basics/set-up-git.

This is a GitHub repository. Git is what everyone uses to collaborate on code; there are important commands to know like clone, pull, add, commit, push, and branch, which we will use all the time. GitHub is a nice website to use Git on. There are countless ways to learn from the internet; here's two example links: https://learn.microsoft.com/en-us/training/modules/intro-to-git/, https://www.w3schools.com/git/.

You should make commits often with descriptive commit messages (we joke sometimes but this is the default), and remember to pull before making changes if you are working on an active branch.

I am spoonfed so I like using GitHub Desktop sometimes (https://desktop.github.com/download/), which I like because of merge editing and nice UI. I also add or commit files sometimes using VSCode because it saves like 5 key presses 😃. GitLens is also a helpful extension to see who did what.

I also use Git Bash sometimes instead of Windows powershell (because windows powershell is some cheeks). I don't really remember how I set it up, but you could probably just google it. I have it set to my default on VSCode. This makes some Linux commands runnable. 

## What is Linux?

You are probably using Windows OS (operating system), or if you have a Mac, MacOS. The robot uses Linux. There are a couple Linux command-line things to know
