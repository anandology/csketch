import sys
import itertools
from pathlib import Path

def parse_file(filename):
    """Parses the file and returns the title and description.
    """
    lines = open(filename).readlines()
    docs = [line[len("//"):].strip() for line in itertools.takewhile(lambda line: line.startswith("//"), lines)]

    title, *_description_lines = list(docs)
    description = "\n".join(_description_lines)

    code = "".join(lines[len(docs):])
    return title, description, code

path = Path(sys.argv[1])
title, description, code = parse_file(path)
svg_path =path.with_suffix(".svg")

md = f"""\
# {title}

<img class="sketch-lg" src="../images/{svg_path.name}">

{description}

## Code

```c
{code}
```
"""

print(md)