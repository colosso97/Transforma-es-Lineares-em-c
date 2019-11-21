public class aluno extends herança {
    private float  media;
    private String num_aluno;

    protected float getMedia() {
        return media;
    }

    protected void setMedia(float media) {
        if(media >= 10){
            this.media = media;
        }
    }

    protected String getNum_aluno() {
        return num_aluno;
    }

    protected void setNum_aluno(String num_aluno) {
        this.num_aluno = num_aluno;
    }

    
}