#pragma once
#include "Common.h"

#include "gfx/Model.h"
#include "gfx/AnimatedModel.h"
#include "gfx/Camera.h"
#include "gfx/Cubemap.h"
#include "gfx/FrameBuffer.h"

#include "primitives/Quad.h"
#include "primitives/Cube.h"
#include "PhysicsManager.h"

#include "Entity.h"

// the components <3
#include "components/EngineComponent.h"
#include "components/DebugComponent.h"
#include "components/TransformComponent.h"
#include "components/MeshComponent.h"
#include "components/AnimatedModelComponent.h"
#include "components/ShaderComponent.h"
#include "components/CameraComponent.h"
#include "components/RigidbodyComponent.h"
#include "components/CollisionShapeComponent.h"
#include "components/CameraControllerComponent.h"