# devconf2025
./compile  
./run  

open second terminal

./generate_gcore_to_check_passwords


Confidential Computing settings (krun):

**Update the security limits**:
```
/etc/security/limits.com
@dlandgra       hard    memlock         8589934592
@dlandgra       soft    memlock         8589934592
```

**SELinux**
```
make -f /usr/share/selinux/devel/Makefile container_kvm_gmem_write.pp
make -f /usr/share/selinux/devel/Makefile container_kvm_gmem.pp
semodule -i container_kvm_gmem_write.pp
semodule -i container_kvm_gmem.pp
```

**Attestation server**:
https://github.com/virtee/reference-kbs
cargo build
cargo run

Generate the confidential workload image:
```
buildah mkcw --attestation-url=http://10.6.68.36:8000 --cpus 2 --memory 2048 --passphrase mysecretpassphrase -t snp myprogram-check myprogram-check-cw
```
