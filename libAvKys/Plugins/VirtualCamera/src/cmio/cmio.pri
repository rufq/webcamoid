isEmpty(CMIO_PLUGINS_DAL_PATH):
    CMIO_PLUGINS_DAL_PATH = /Library/CoreMediaIO/Plug-Ins/DAL
isEmpty(CMIO_DAEMONS_PATH):
    CMIO_DAEMONS_PATH = ~/Library/LaunchAgents
isEmpty(CMIO_PLUGIN_NAME):
    CMIO_PLUGIN_NAME = AkVirtualCamera
isEmpty(CMIO_PLUGIN_ASSISTANT_NAME):
    CMIO_PLUGIN_ASSISTANT_NAME = AkVCamAssistant
isEmpty(CMIO_PLUGIN_DEVICE_PREFIX):
    CMIO_PLUGIN_DEVICE_PREFIX = /akvcam/video
isEmpty(CMIO_PLUGIN_VENDOR):
    CMIO_PLUGIN_VENDOR = "Webcamoid Project"
isEmpty(CMIO_PLUGIN_PRODUCT):
    CMIO_PLUGIN_PRODUCT = $$CMIO_PLUGIN_NAME

DEFINES += \
    CMIO_PLUGINS_DAL_PATH=\"\\\"$$CMIO_PLUGINS_DAL_PATH\\\"\" \
    CMIO_PLUGINS_DAL_PATH_L=\"L\\\"$$CMIO_PLUGINS_DAL_PATH\\\"\" \
    CMIO_DAEMONS_PATH=\"\\\"$$CMIO_DAEMONS_PATH\\\"\" \
    CMIO_PLUGIN_NAME=\"\\\"$$CMIO_PLUGIN_NAME\\\"\" \
    CMIO_PLUGIN_NAME_L=\"L\\\"$$CMIO_PLUGIN_NAME\\\"\" \
    CMIO_PLUGIN_ASSISTANT_NAME=\"\\\"$$CMIO_PLUGIN_ASSISTANT_NAME\\\"\" \
    CMIO_PLUGIN_ASSISTANT_NAME_L=\"L\\\"$$CMIO_PLUGIN_ASSISTANT_NAME\\\"\" \
    CMIO_PLUGIN_DEVICE_PREFIX=\"\\\"$$CMIO_PLUGIN_DEVICE_PREFIX\\\"\" \
    CMIO_PLUGIN_VENDOR=\"\\\"$$CMIO_PLUGIN_VENDOR\\\"\" \
    CMIO_PLUGIN_PRODUCT=\"\\\"$$CMIO_PLUGIN_PRODUCT\\\"\"