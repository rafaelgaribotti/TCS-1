git config --global github.user luis.becker@acad.pucrs.br
git config --global github.token $GITHUB_TOKEN
git add coverage/*
git pull
git commit -m "travis test files"
git push origin HEAD:warmup --quiet
