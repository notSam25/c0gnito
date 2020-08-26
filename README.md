# c0gnito

#How to use

the included source code for this project is all you need besides an account for https://c0gnito.cc/
To setup the rest of the source refer to the setup instructions

#Setup instructions

* include inside the source are commented lines of code, Please read these for it tells your EXACTLY how to setup this for your login application(EX: //message goes here)

* Build Tools, this project is set for Debug x64 you can change out this for a diffrent toolset by downloading a diffrent option from https://c0gnito.cc/dashboard/documentation

* Public  key setup - there is a commented section at the start of the project labeled "//replace this with your public Key", to find your public key it is located by clicking the
"manage" button on your application(https://c0gnito.cc/dashboard)

* DLL hash check - to help stop people from cracking your application a hash check will help. to replace this to your "c0gnito.dll" hash you must take the output from "cout << hash(contents.str()) << endl" this is on Line: 52. on line: 54 there is a string of numbers, you should replace your outputted hash into there

#Video tutorialss

there are some video tutorials on the official youtube channel for c0gnito(https://www.youtube.com/channel/UCnjb78K4FK-mHdCGHqZzLcg)

Keep in mind only the C++ labeled tutorials will work because this is a C++ source code
if further help is needed contact someone in the c0gnito discord server(https://discord.gg/PKH5ysw) or me(notWeedle#0133)
