#!/bin/sh

rake generate
mkdir -p public/_posts public/me
rake deploy

git add -A
git commit -a -m "udpate"
git push origin source

