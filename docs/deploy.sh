#!/usr/bin/env bash

if [[ "$TRAIVS_BRANCH" == "dev" ]]; then
   /bin/doxygen docs/config
   /bin/ssh athena "rm -rf /var/www/html/lightsplusplus/*"
   /bin/scp -r html/* /var/www/html/lightsplusplus/
fi