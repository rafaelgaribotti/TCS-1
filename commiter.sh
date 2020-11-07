git config --global github.user LufeSantos
git config --global github.token $GITHUB_TOKEN
git add coverage/*
git pull
git commit -m "travis test files"
git push https://$(GITHUB_TOKEN)@github.com/LufeSantos/TCS.git HEAD:warmup --quiet
