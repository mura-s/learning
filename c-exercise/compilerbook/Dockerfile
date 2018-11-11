FROM gcc:8

RUN mkdir /app
ADD . /app
WORKDIR /app

RUN make
CMD ["make", "test"]