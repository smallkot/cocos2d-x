set(SPINE_SRC
  Animation.c
  AnimationState.c
  AnimationStateData.c
  Atlas.c
  AtlasAttachmentLoader.c
  Attachment.c
  AttachmentLoader.c
  Bone.c
  BoneData.c
  BoundingBoxAttachment.c
  Event.c
  EventData.c
  extension.c
  IkConstraint.c
  IkConstraintData.c
  Json.c
  MeshAttachment.c
  PolygonBatch.cpp
  RegionAttachment.c
  Skeleton.c
  SkeletonAnimation.cpp
  SkeletonBounds.c
  SkeletonData.c
  SkeletonJson.c
  SkeletonRenderer.cpp
  Skin.c
  SkinnedMeshAttachment.c
  Slot.c
  SlotData.c
  spine-cocos2dx.cpp
)

include_directories(
  ..
)

add_library(spine STATIC
  ${SPINE_SRC}
)

set_target_properties(spine
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

