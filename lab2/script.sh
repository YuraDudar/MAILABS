#!/bin/sh
git init
git add .
git status
git commit -m $1
git remote add origin $2
git config —global user.name $3
git config —global user.email $4
git push origin master
