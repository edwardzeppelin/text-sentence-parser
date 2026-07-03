# Sentence Extractor

A C++ console application that reads a text file, parses it into individual sentences, and filters out question (`?`) and exclamation (`!`) sentences.

## How it Works

1. The program opens a local file named `text.txt`.
2. It processes the text character by character to detect sentence boundaries based on `.`, `?`, and `!`.
3. It separates questions and exclamations, then prints them grouped together to the console.
