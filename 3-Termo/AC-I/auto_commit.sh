#!/bin/bash

COMMIT_MESSAGE="${1:-'Atualização automática'}"

git add .

git commit -m "$COMMIT_MESSAGE"

git push origin main

