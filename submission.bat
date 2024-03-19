@echo off
set http_proxy=http://127.0.0.1:7890 & set https_proxy=http://127.0.0.1:7890
git fetch
git pull
if exist submission.zip del submission.zip
winrar a -r submission.zip *.cpp *.h CMakeLists.txt
