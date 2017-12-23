#ifndef ANIMATIONS_ENUM_H
#define ANIMATIONS_ENUM_H

enum class ActorActions {
    Stay, Up, Down, Left, Right, BombStay, BombExplode
};
#define ACTOR_ANIMATION_POOL Singleton<AnimationPool<ActorActions>>::instance()

#endif // ANIMATIONS_ENUM_H
