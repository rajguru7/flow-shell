# flow-shell

## Overview

This project is designed to parse and execute commands defined in a flow file.
The flow file specifies nodes with commands that can be executed sequentially.


## Project Structure

- **flow.c**: Main source code file that contains the logic for parsing the flow
  file and executing commands.
- **Makefile**: Contains the instructions to compile the `flow.c` file.
- **tests/**: Contains test cases for the project.
- **docs/**: Contains documentation and notes related to the project.

## Compilation

To compile the project, run the following command:

```sh
make
```

This will generate an executable named `flow`.

## Usage

To run the executable, use the following command:

```sh
./flow <flow_file> <action_name>
```

- `<flow_file>`: Path to the flow file.
- `<action_name>`: Name of the action to execute.

### Example

```sh
./flow flowfile.flow list_files
```

## Flow File Format

The flow file should contain nodes and commands in the following format:

```
node=<node_name>
command=<command>
```

### Example

```
node=list_files
command=ls

node=word_count
command=wc

pipe=doit
from=list_files to=word_count
```

## Notes

- Ensure that the flow file is correctly formatted to avoid parsing errors.

## License

This project is licensed under the MIT License.

Feel free to modify the content as per your specific requirements.
