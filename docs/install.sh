#! /bin/bash
#
# Script to download and install csketch
#

set -e

VERSION=0.1.2
URL="https://github.com/anandology/csketch/releases/download/v$VERSION/csketch-$VERSION.tar.gz"

echo "---"

cat<<END
         __        __       __
   _____/ /_____  / /______/ /_
  / ___/ //_/ _ \/ __/ ___/ __ \\
 (__  ) ,< /  __/ /_/ /__/ / / /
/____/_/|_|\___/\__/\___/_/ /_/

END

echo
echo "-> Downloading and installing csketch $VERSION"
curl -sSf -L $URL | tar xvzf -

echo
echo "-> Building the library"
(cd sketch && make)

echo
echo "-> Successfully downloaded and built the csketch $VERSION in $PWD."

echo
echo "-> Thank you for downloading csketch."
echo
echo "-> For documentation, usage and examples, please visit:"
echo "   https://anandology.github.io/csketch/"