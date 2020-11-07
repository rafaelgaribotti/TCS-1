
git config --global user.email "travis@travis-ci.org"
git config --global user.name "Travis CI"
git add coverage/*
git pull
git commit -m "travis test files"
git push origin HEAD:warmup --quiet
