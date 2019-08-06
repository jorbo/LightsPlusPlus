#!/usr/bin/env bash
/bin/doxygen config
/bin/ssh athena "rm -rf /var/www/html/lightsplusplus/*"
/bin/scp -r html/* athena:/var/www/html/lightsplusplus/
