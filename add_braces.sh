#!/bin/bash

# Function to add brackets around a quoted string
add_brackets() {
  echo "(${1:1:-1})"
}

# Check if the file exists
if [ -f "$1" ]; then
  # Read the content of the file
  content=$(<"$1")

  # Regex pattern to match quoted strings
  pattern='"[^"]*"'

  # Use sed to apply the regex pattern and the function to add brackets
  updated_content=$(echo "$content" | sed "s/$pattern/$(add_brackets '&')/g")

  # Write the updated content back to the file
  echo "$updated_content" > "$1"
else
  echo "Error: File not found."
fi