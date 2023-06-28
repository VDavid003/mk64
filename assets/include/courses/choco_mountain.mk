CHOCO_MOUNTAIN_DIR := assets/courses/choco_mountain

CHOCO_MOUNTAIN_PNG := \
$(CHOCO_MOUNTAIN_DIR)/gTextureChocoMountainWall.png \
$(CHOCO_MOUNTAIN_DIR)/gTextureChocoMountainRock.png

CHOCO_MOUNTAIN_EXPORT_SENTINEL := $(CHOCO_MOUNTAIN_DIR)/.export

ASSET_DIRECTORIES += $(CHOCO_MOUNTAIN_DIR)

$(BUILD_DIR)/courses/flower_cup/choco_mountain/course_data.inc.o: $(CHOCO_MOUNTAIN_PNG:%.png=%.inc.c)

$(CHOCO_MOUNTAIN_PNG:%.png=%.inc.c): %.inc.c : %.png
	$(N64GRAPHICS) -i $@ -g $< -s u8 -f rgba16

$(CHOCO_MOUNTAIN_PNG): $(CHOCO_MOUNTAIN_EXPORT_SENTINEL) ;

$(CHOCO_MOUNTAIN_EXPORT_SENTINEL): $(ASSET_DIR)/courses/choco_mountain.json
	$(ASSET_EXTRACT) $(BASEROM) $<
	touch $@
