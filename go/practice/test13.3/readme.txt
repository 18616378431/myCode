If you need to have bzip2 first in your PATH run:
  echo 'export PATH="/usr/local/opt/bzip2/bin:$PATH"' >> /Users/wangjiankang/.bash_profile

For compilers to find bzip2 you may need to set:
  export LDFLAGS="-L/usr/local/opt/bzip2/lib"
  export CPPFLAGS="-I/usr/local/opt/bzip2/include"