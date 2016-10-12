#!/bin/sh

# Use .profile instead of .bashrc for Mac
BASHRC=~/.bashrc
VIMRC=~/.vimrc
CPP=~/.vim/cpp

if [ -e $BASHRC ]; then
  echo "Bashrc file $BASHRC already exists (not overriding it).";
else
  cp bashrc $BASHRC
  echo "Bashrc file $BASHRC created.";
fi

if [ -e $VIMRC ]; then
  echo "Vimrc file $VIMRC already exists (not overriding it).";
else
  cp vimrc $VIMRC
  echo "Vimrc file $VIMRC created.";
fi

mkdir -p ~/.vim/
if [ -e $CPP ]; then
  echo "C++ template $CPP already exists (not overriding it).";
else
  cp cpp $CPP
  echo "C++ template $CPP created.";
fi
