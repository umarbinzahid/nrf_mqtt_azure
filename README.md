# Azure IoT Hub Connection with nRF7002 (Zephyr Project)

This project demonstrates how to connect the Nordic Semiconductor **nRF7002** Wi-Fi 6 development kit to **Azure IoT Hub** using **Shared Access Signature (SAS) token authentication**.

---

## 📋 Features

- Static Wi-Fi credential connection
- Secure MQTT connection to Azure IoT Hub using SAS token
- Uses Zephyr Kconfig system for easy configuration
- Compatible with `nrf7002dk/nrf5340/cpuapp/ns`

---

## ⚙️ Configuration

### 🔐 Azure IoT Hub Credentials

Set the following Kconfig options to configure your connection to Azure IoT Hub. These can be defined in `prj.conf` or via `menuconfig`.

| Kconfig Variable | Description |
|------------------|-------------|
| `SAMPLE_CLOUD_AZURE_USERNAME`       | Azure IoT Hub username (`<hostname>/<device_id>/?api-version=2021-04-12`) |
| `SAMPLE_CLOUD_AZURE_PASSWORD`       | SAS token (used as password) |
| `SAMPLE_CLOUD_AZURE_CLIENT_ID`      | Azure device ID |
| `SAMPLE_CLOUD_AZURE_HOSTNAME`       | IoT Hub hostname (e.g., `your-hub.azure-devices.net`) |
| `SAMPLE_CLOUD_AZURE_SERVER_ADDR`    | MQTT broker address (only required if DNS is disabled)  |
| `SAMPLE_CLOUD_AZURE_SERVER_PORT`    | MQTT port (Default `8883`) |

### 📶 Wi-Fi Credentials

To use static Wi-Fi credentials, add the following lines to your **overlay configuration file**:  
`nrf7002dk_nrf5340_cpuapp_ns.conf`

```conf
CONFIG_WIFI_CREDENTIALS_STATIC_SSID="YourSSID"
CONFIG_WIFI_CREDENTIALS_STATIC_PASSWORD="YourPassword"
CONFIG_WIFI_CREDENTIALS_STATIC=y
```

## 🧱 Building and Flashing

Simply use the nRF Connect extension in Visual Studio Code to build and flash the firmware. The commands should work as well, but I haven’t tested them.

### 🔨 Build the Firmware
```
west build -pristine --board nrf7002dk/nrf5340/cpuapp/ns
```
### 🚀 Flash to Device
```
west flash -r nrfjprog --erase
```