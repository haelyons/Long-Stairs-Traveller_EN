#!/bin/bash

# Check if the correct number of arguments is provided
if [ $# -ne 1 ]; then
	  echo "Usage: $0 <filename>"
	    exit 1
    fi

    filename=$1

    # Check if the file exists
    if [ ! -f "$filename" ]; then
	      echo "Error: File not found."
	        exit 1
	fi

	# Function to add braces around quoted text in a given string
	add_braces_to_quoted_text() {
		  local input_string=$1
		    local result_string=""

		      while [[ $input_string =~ (.*?)(\"[^\"]+\")(.*) ]]; do
			      result_string+="${BASH_REMATCH[1]}_(${BASH_REMATCH[2]})"
				      input_string=${BASH_REMATCH[3]}
				        done

					  result_string+=$input_string
					    echo "$result_string"
				    }

				    # Process the file line by line, adding braces around quoted text
				    while IFS= read -r line; do
					      line_with_braces=$(add_braces_to_quoted_text "$line")
					        echo "$line_with_braces"
					done < "$filename"

