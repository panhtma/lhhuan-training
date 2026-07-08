FROM gcc:latest
WORKDIR /app
COPY . .
RUN apt-get update && apt-get install -y libhiredis-dev
RUN make
CMD ["./redis"]