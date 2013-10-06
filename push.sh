#!/bin/sh

find source/code/ -executable -type f -exec rm {} \;
find source/code/ -name "*.o" -exec rm {} \;

rake generate
mkdir -p public/_posts public/me
rake deploy

git add -A
git commit -a -m "udpate"
git push origin source

