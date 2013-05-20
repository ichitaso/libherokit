GO_EASY_ON_ME=1

include theos/makefiles/common.mk

TWEAK_NAME = libherokit
libherokit_FILES = Tweak.xm
libherokit_FRAMEWORKS = Foundation UIKit AVFoundation AudioToolbox
libherokit_PRIVATE_FRAMEWORKS = BackBoardServices

include $(THEOS_MAKE_PATH)/tweak.mk