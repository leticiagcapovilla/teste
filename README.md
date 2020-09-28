# PmacSlits

This project is a simple example of coordinated motion on Power PMAC, controlling the gap and the offset of a two motors slit.

# Downloading PowerPMAC programs

* Open PowerPMAC IDE
* Load `./Motor4_Testing/Motor4_Testing.PowerPmacSuite_sln` solution
* If the project has not been loaded, right click on solution and add project `./Motor4_Testing/Motor4_Testing/Motor4_Testing.ppproj`
* Right click on project and `Build and Download all programs`

# Compile and running slit IOC

First of all you must set PowerPMAC brick IP address on `st.cmd`

```sh
## Create SSH Port to communicate with Power PMAC
# TODO Set here your brick IP, login and password
drvAsynPowerPMACPortConfigure("BRICK1port", "192.168.0.200", "root", "deltatau", "0", "0", "0")
```

Then run using the following commands:

```sh
cd $TOP
make
cd iocBoot/iocslit
./st.cmd
```
