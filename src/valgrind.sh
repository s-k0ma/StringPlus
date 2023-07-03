#!/bin/bash
make vlgrnd
valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./vlgrnd