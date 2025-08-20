FROM fedora:41

# Just enough to run and inspect (ps)
RUN dnf -y install procps-ng && dnf clean all

# Copy precompiled binary
COPY myprogram /root/myprogram

# Default run
CMD ["/root/myprogram"]

