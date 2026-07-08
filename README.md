# gen-pass

A blazing fast, lightweight CLI password generator written in C++.

# how to install

```bash
git clone https://github.com/Minish777/gen-pass.git
cd gen-pass
g++ -O3 main.cpp -o genpass
```
# how to use

```bash
mv genpass ~/.local/bin/ # (optional) to use everywhere
```
for help:
```bash
genpass -h
```


password generation with special symbols:
```bash
genpass [password lenght]
```
password generatin without special symbols:
```bash
genpass -n [password lenght]
```
