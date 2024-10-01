## WHAT ARE THESE?

#### Cloning the repository

The repository is reasonably large, and it's unlikely that you need the full history (~200 MB). If you are happy to wait for it all to download, run:

```
git clone https://github.com/ter.git
```

To clone only the most recent version, instead use a 'shallow clone':

```
git clone --depth=1 https://github.com/ter.git
```

If you want to add in the full history later on, perhaps to run `git blame` or `git log`, run `git fetch --depth=1000000` 
