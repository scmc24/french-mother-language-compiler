#!/bin/bash

# Create Duala equivalents for all French examples
cd /home/zaz/Documents/Github/french-mother-language-compiler/C/Duala/example_programs

# Function to convert French keywords to Duala
convert_to_duala() {
    local input_file="$1"
    local output_file="$2"
    
    sed 's/debut/mbɔmbɔ/g; s/fin/suka/g; s/entier/ndambo/g; s/lire/yɛnɛ/g; s/ecrire/kɔma/g; s/si/sɔ/g; s/alors/tɛ/g; s/sinon/kɛma/g; s/finsi/sukasi/g; s/tant_que/mbɛlɛ/g; s/faire/sala/g; s/fintant/sukambɛlɛ/g' "$input_file" > "$output_file"
}

# Convert existing French examples to Duala
french_dir="/home/zaz/Documents/Github/french-mother-language-compiler/C/Francais/example_programs"

# Convert all .fr files to .du files
for french_file in "$french_dir"/*.fr; do
    if [ -f "$french_file" ]; then
        filename=$(basename "$french_file" .fr)
        duala_file="${filename}.du"
        convert_to_duala "$french_file" "$duala_file"
        echo "Converted $filename.fr to $duala_file"
    fi
done

echo "All Duala examples created successfully!"
