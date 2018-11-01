# makeBash

makeBash is a CLI written in C that recieves terminal commands from the user and creates an executable shell script from them.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Installing

To install makeBash, simply download the repo and run the install script as the super user:

```
sudo ./install.sh
```

This will install the C interpreter tcc if not already installed.

## Using makeBash

After installing, makeBash can be run as a CLI by entering

```
makeBash
```
The title of the script can also be entered as a command line argument. For example, to create a shell script titled: test.sh, the user may enter

```
makeBash test
```
or
```
makeBash test.sh
```


## Authors

* **Matthew Sumpter**

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

