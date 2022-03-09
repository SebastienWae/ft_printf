build:
	$(MAKE) -C ./srcs

test: build
	$(MAKE) -C ./tests run_test