git config --global github.user samueldfinatto@gmail.com
git config --global github.token $GITHUB_TOKEN
git add coverage/*
git pull
git commit -m "travis test files"
git push